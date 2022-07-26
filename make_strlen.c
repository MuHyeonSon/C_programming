#include <stdio.h>      

int make_strlen(const char* string); //구현한 strlen함수 선언

int main()                
{
    // strlen 함수 구현
    // 사용자로부터 문자열을 입력 받은 뒤 그 문자열의 길이 출력하기

    char s[10];

    printf_s("문자열을 입력하세요(문자열의 최대 길이는 9) : ");
    scanf_s("%s", s, sizeof(s));  //사용자로부터 문자열을 입력받는다
    printf_s("입력하신 문자열 '%s'의 길이는 %d 입니다\n",s, make_strlen(s)); // 문자열이 담긴 배열을 인수로 받아서 정의한 strlen 함수로부터 문자열의 길이를 구한다

    return 0;
}

int make_strlen(char* string)
{
    if (string == NULL) //메모리가 할당이 되지 않았는지 (NUll포인터인지) 체크
    {
        printf_s("NUll 포인터 입니다!!!\n"); // 경고문구 출력
        exit(1); // 에러 메세지 종료
    }
    else //메모리가 할당 되었다면(NULL 포인터가 아니라면)
    {

        int length_of_string = 0; // 문자열의 길이를 저장할 변수 선언 및 초기화

        for (int i = 0; string[i] != NULL; i++) // 반복문(문자열의 문자열이 담긴 배열의 값이 NULL이 아닐 때까지 반복문 실행)
        {
            length_of_string += 1; // 해당 문자가 NULL이 아니라면 문자의 길이를 1 증가시킨다
        }
        if (length_of_string == 0) //값 올바른지 확인(입력문자의 최대길이 초과했는지)
        {
            printf_s("잘못된 입력입니다! 입력 문자열의 길이를 확인하세요!\n");
            exit(1); // 에러메세지 종료 
        }
        // 터미널 NULL을 제외한 문자열의 문자 수를 반환

        return length_of_string; // 계산된 문자열의 길이를 return

    }
}

/*
strlen 함수 직접 구현하기
    프로그램 설명
    1. 3번 줄에서 문자열의 길이를 계산하여 return해주는 함수 선언.
    2. main 함수 10번 줄에서 문자열을 담을 배열을 선언.
     배열의 길이는 10으로 문자열의 끝을 알려주는 NULL을 포함하여 9개 문자의 문자열을 저장가능.
    3. 13번 줄에서 사용자로부터 문자열을 입력받는다.
    4. 14번 줄에서 입력받은 문자열의 길이를 출력해주고 문자열의 길이는 make_strlen 함수로 부터 구해진다.
        해당 함수는 배열을 입력받고 배열명은 배열의 첫 요소의 주소를 의미하므로 주소를 매개변수로 넘겨준다.
    5. 19번 줄에서 부터 make_strlen 함수를 정의한다. main에서 매개변수로 주소를 넘겨주었으므로
        주소를 저장하는 변수인 pointer 변수("char* string")로 주소를 받는다.
    6. 다음으로 함수의 argument에 대한 validation을 진행한다.
        - NULL 포인터 체크
            21번 줄에서 넘겨받은 주소 값이 NULL인지(메모리 할당 받지 못했는지) 확인
            -> NULL이라면 경고메세지 출력 후 프로그램 종료
        - 값이 올바른지 체크
            35번 줄에서 for문 연산이 끝난 후 만약 문자열의 길이가 9를 초과하게되면
            문자열의 길이를 저장하는 length_of_string가 0이 된다. 왜나하면 9를 초과하면 배열에 문자열이 저장되지
            않고 입력받은 문자열은 ""가된다.
            -> 따라서 문자열의 길이를 저장하는 변수  length_of_string가 0이라면 경고메시지를 출력하고
                프로그램을 종료한다.
    7. 문자열길이 계산
        반복문(for문)을 통해 배열의 요소를 처음부터 마지막까지 하나씩 가져와 해당 요소가 NULL인지 확인한다.
        만약 NULL이 아니면 해당문자열은 문자열의 마지막임을 뜻하는 NULL값이 아닌 유효한 문자이므로
        배열의 요소의 위치를 접근하기 위한 변수 i의 값을 1증가 시킴으로써 다음 차례의 반복문을 실행할 때
        다음 배열의 요소를 가리킴으로 다음 문자를 접근한다.
        또한 문자열의 길이를 저장하는 변수  length_of_string의 값을 1만큼 증가시킨다.
        NULL 이면 해당 반복문을 빠져나온다.
        -> 최종적으로 계산된 문자열의 길이를 저장하고 있는  length_of_string를 return 한다.
    8. 메인함수에서 함수의 반환값을 받아 계산된 문자열의 길이를 출력한다.

    *수정전 받았던 피드백*
    
    개선해야될 것들
    
    1. printf의 safe 함수를 사용할 것
    2. 안쓰는 헤더파일을 지우는게 좋다.
    3. argument에 대한 validation (NULL 포인터 확인, 값 올바른지 확인)
    4. 코딩컨벤션 (scnaf, printf 등에서 띄어쓰기 공백 같은 것 정한 규칙에 따라 모두 일괄적용)
    5. 주소값이 NULL 일 때 프로그램이 죽지 않는 방법을 고민해볼 것
     -> NULL 포인트 체크하거나
        실무에서는 다음과 같이 포인터가 NULL인지 확인한 뒤 NULL이면 메모리를 할당하는
        패턴을 주로 사용한다고 한다.

            if (ptr == NULL)         // ptr이 널 포인터라면
            {
                ptr = malloc(1024);   // 1024바이트만큼 메모리 할당
            }
    6. 값이 NULL일 때 처리하는 방법
     -> scanf_s 사용시 엔터를 입력받으면 프로그램이 진행되지 않고
       문자열이 들어와야 프로그램이 진행되는데 엔터를 입력했을 때 문자열을 입력하라는 메시지를 출력하고자 한다.
       그러기 위해 엔터가 어떤 값을 어떻게 인식하여 할 수 처리할 수 있는지 scanf_s 외에 다른 함수를 사용하여
       문자열을 입력받아야 하는지
       
       -> scanf 함수와 scanf_s 함수는 포멧에 맞지 않는 부분이 있으면 더 이상 작업을 진행하지 않아요.
        그리고 %s 포멧은 공백이나 탭, 엔터를 만나기 전까지 문자열만 변환해요.
        공백을 포함해서 문자열을 입력받을 때는 gets나 gets_s를 사용하세요.
        출처:// https://ehclub.co.kr/656 [언제나 휴일:티스토리]

*/
