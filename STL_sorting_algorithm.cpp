#include <iostream> //iostream 헤더파일 include
					//이 문장은 전처리기(preprocessor)에 대한 지시문으로 c++ 소스 파일을 컴파일하기 전에 <iostream> 헤더파일을
					// 읽어 C++소스파일 안에 삽입할 것을 지시한다.
					// <iostream>헤더파일에는 C++표준  입출력을 위한 클래스와 객체가 선언되어 있음.
#include <set> // 컨테이너 set class 헤더파일 include
#include <vector> //컨테이너 vector class 헤더파일 include
#include <string> //wstring 사용하기 위해 string 헤더파일을 include
#include <locale> // 숫자 포매팅 방식, 날짜/시간 포매팅 방식, 화폐 포매팅 방식
					// 문자 순서, 종이 크기 등의 여러가지 내용들이 저장됨
					// 이것들이 국가, 언어마다 달라지는 부분에 대한 정보를
					// 저장해둔 것이 "locale"이다.
					//e.g) 우리나라의 경우 큰 숫자가 있을 때 자리수를 끊기 위해 컴마를 사용
					// but 유럽의 경우 dot(.)을 사용
// #include <cstdlib>  // 난수를 생성하는 rand()라는 함수를 가진 헤더파일(<cstdlib>) 인클루드 
using namespace std; // std namespace에 선언된 모든 이름에 std:: 생력
//#include <Shlwapi.h> //This header is used by The Windows Shell. For more information, see:
					 //Shell Light-weight Utility Library
//#pragma comment(lib, "shlwapi.lib") //pragma commentsms 라이브러리를 링크시켜준다
									//이걸 사용함으로써 굳이 project settings에서 link tab에 있는
									//input에 .lib file을 쓰지 않고 #pragma comment  ( lib, "xxx.lib" )라고
									//써도 되는 거임

//struct Compare { // set 컨테이너 안에 있는 데이터들을 정렬하기 위한 정렬 알고리즘에 대한  구조체??
				 // set 컨테이너의 정렬 구조체
	// operator()라는 멤버변수선언
//	bool operator() (const wstring &a, const wstring &b) const{ //const가 붙은 멤버함수 : 멤버변수를 읽기전용으로 사용하겠다는 것(멤버함수 내부에서는 멤버 변수 값을 변경하지 못함)
		//return !(StrCmpLogicalW(a.c_str(), b.c_str()) == -1 ? true : false); // StrCmpLogicalW 함수는 두unicode string을 비교한다 (문자열안에있는숫자들은 text가 아닌 숫자로 간주됨)
																			 // 0을 return : 문자열들이 동일하다면
																			 // 1을 return : 왼쪽이 가리키는게 (오른쪽이 가리키는 것보다) 더크다면
																			 // -1을 return : 오른쪽이 가리키는게 더크다면
																			 //	c_str()  : C string 형식으로 변환한다.string class는 C에서의 char_를 손쉽게 저장할 수 있도록 도와주는 STL 함수
																			 // a ? b : c는, a가 참이면 b로 평가되고, 그 밖에는 c로 평가된다.
																			 // 즉 왼쪽 string과 오른쪽 string을 C string으로 바꾸고 왼쪽이 더 크면 최종적으로 1을 return
//	}                                                                        //    오른쪽 string이 더 크면 최종적으로 0을 return
																			 
//};
//////////////////sorting 알고리즘///////////////////////////////////////////
struct my_order {
	bool operator() (const wstring &left, const wstring &right) const
	{
		//컨테이너 안에 원소로 들어가는 것들은 모두 문자열이기 때문에
		//if (left.size() == right.size()) { // 같으면 오름차순으로 비교하고
		//	return left < right;
		//}
		//else {
		//	return left.size() < right.size(); // 같지 않으면 사이즈를 비교하라
		//}
		wcout << left << endl;
		vector<wstring> v_l; // set의 기존의 한 원소(문자열)에 대해 문자 단위로 접근하기 위한 컨테이너
		vector<wstring> v_R; // set에 원소로 삽입할 한 문자열에 대해 문자 단위로 접근하기 위한 컨테이너

		
	}
};
//////////////////////////////////////////////////////////////////////////////


int main() {
	locale::global(std::locale("kor")); //전체locale 설정 (전체 locale의 설정을 Korean으로)
	wcout.imbue(std::locale("kor")); //전역 locale 설정 (전역 locale의 설정을 korean으로) / 이게 무엇을 하는건지??
									//전체와 전역 무슨 차이인지???
	// 생성자 //
	set<wstring, my_order> s;      // 오름차순(wstring 값을 담는 set선언), 기본 값 : less<int> wstring
	//set<int, greater<int>> set;      //내림차순

	set<wstring>::iterator iter; //위에서 정의한 set의 iterator를 정의
	// 삽입, 삭제 //
	s.insert(L"00001");
	s.insert(L"2");
	//s.insert(L"111번");
	//s.insert(L"11번");
	//s.insert(L"4번");
	//s.insert(L"3번");
	//s.insert(L"03번");
	//s.insert(L"2번");
	//s.insert(L"1ㅊ$#@321");
	//s.insert(L"10번");
	//s.insert(L"1번");
	//s.insert(L"1Av가7");
	for (iter = s.begin(); iter != s.end(); iter++)
		wcout << (*iter) << "\n";
	return 0;
}


/*
#include <stdio.h>

int main()
{
//
char c1 = '0';
char c2 = '3';
char c3 = '3';
printf_s("%d\n",c1+c2); //'03'
printf_s("%d\n", c3); //'3'
printf_s("%d\n", c3);
return 0;


char c1 = '#';
char c2 = '[';
char c3 = '@';
printf_s("%d\n", c1);
printf_s("%d\n", c2);
printf_s("%d\n", c3);
return 0;
}

*/
