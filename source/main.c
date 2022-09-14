#include <stdio.h>
#include <string.h>
enum {
    EXIT,
    INSERT,
    SEARCH,
    DELETE,
    PRINT_ALL
};
typedef struct tel{
    char name[30];
    char num[20];
}tel;
tel arr[20] ={
    {"홍길동", "01020655622"},
    {"김철수", "01056432142"},
    {"이학우", "01064321534"}
};
int idx = 3; 
void InsertMember(){

    if(idx == 20){
        printf("더이상 저장할 공간이 없습니다\n");
        return;
    }
    printf("이름 입력 : ");
    scanf(" %s",arr[idx].name);
    printf("전화번호 입력 : ");
    scanf(" %d",&arr[idx].num);
    idx++;
    printf("연락처 등록 완료\n");
}
void PrintAllMember(){
    
    printf("전체 연락처 출력\n\n");
    for(int i=0;i<idx;i++)  
        printf("%s %s\n",arr[i].name, arr[i].num);  
    printf("\n");
}
void SearchMember(){
    char str[30];
    printf("검색할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            printf("%s %s\n",arr[i].name, arr[i].num);  
            return;
        }
    }
    printf("검색 결과가 없습니다.\n");
}
void DeleteMember(){
    char str[30];
    printf("삭제할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            for(int j=i;j<idx-1;j++)
                arr[j] = arr[j+1];
            idx--;
            return;
        }
    }
    printf("삭제할 데이터가 없습니다.\n");
}
int main(void){
    int no = -1;

    while(no != EXIT){
        puts("--- 연락처 관리 프로그램 ---");
        puts("1. 연락처 등록");
        puts("2. 연락처 검색");
        puts("3. 연락처 삭제");
        puts("4. 전체 연락처 검색");
        puts("0. 프로그램 종료");
        puts("원하시는 메뉴 번호 입력 : ");
        scanf("%d",&no);

        switch(no){
            case INSERT:
                InsertMember();
                break;
            case SEARCH:
                SearchMember();
                break;
            case DELETE:
                DeleteMember();
                break;
            case PRINT_ALL:
                PrintAllMember();
                break;
        }
    }

    return 0;
}
