// 모든 표준 라이브러리를 포함하는 헤더
// algorithm, iostream, vector 등 모든 표준 라이브러리 포함
#include<bits/stdc++.h> 
using namespace std;

// long long 자료형을 ll로 줄여서 사용
// 큰 수를 다룰 때 사용 (이 코드에서는 실제로 사용되지 않음)
typedef long long ll; 

// 전역 변수 선언
int a[100004],    // 원본 숫자들을 저장할 배열
    b, c,         // b: 구간의 시작 인덱스, c: 구간의 끝 인덱스
    psum[100004], // prefix sum(누적 합) 저장 배열
    n,            // 입력받을 숫자의 개수
    m;            // 구간 합을 구할 횟수

int main() {
    // --- 입출력 최적화 설정 ---
    // C와 C++ 표준 스트림의 동기화를 해제하여 cin/cout 속도 향상
    ios_base::sync_with_stdio(false); 
    // cin과 cout의 묶음을 해제하여 입출력 속도 향상
    cin.tie(NULL); 
    cout.tie(NULL);
    
    // n과 m 입력받기
    cin >> n >> m;
    
    // 1부터 n까지 숫자를 입력받으면서 누적 합 계산
    for(int i = 1; i <= n; i++) {
        cin >> a[i];  // 현재 숫자 입력받기
        
        // 누적 합 계산
        // psum[i]는 1번부터 i번까지의 모든 수의 합
        // 예: i가 3이면, psum[3] = a[1] + a[2] + a[3]
        psum[i] = psum[i-1] + a[i];
    }

    // m번 동안 구간 합 질의 처리
    for(int i = 0; i < m; i++) {
        cin >> b >> c;  // 구간의 시작(b)과 끝(c) 입력받기
        
        // 구간 합 계산 및 출력
        // psum[c] : 1번부터 c번까지의 합
        // psum[b-1] : 1번부터 (b-1)번까지의 합
        // 따라서 psum[c] - psum[b-1]는 b번부터 c번까지의 합이 됨
        cout << psum[c] - psum[b-1] << "\n";
    }
    return 0;
}

/*
5 3      // n=5(숫자 개수), m=3(질의 개수)
1 2 3 4 5 // 5개의 숫자
1 3      // 첫 번째 질의: 1~3 구간: 1~3 구간: psum[3] - psum[0] = 6 - 0 = 6 출력
2 4      // 두 번째 질의: 2~4 구간: 2~4 구간: psum[4] - psum[1] = 10 - 1 = 9 출력
5 5      // 세 번째 질의: 5~5 구간: 5~5 구간: psum[5] - psum[4] = 15 - 10 = 5 출력


*/