#include<bits/stdc++.h> 
using namespace std;

string dopa = "abcde";
void print(string txt) {
    cout << txt << '\n';
}
int main() {
    // Q1. 앞에서부터 3개의 문자열 출력
    string dopa2 = dopa.substr(0, 3);
    print(dopa2);

    // Q2. 해당 문자열을 거꾸로 해서 출력
    reverse(dopa2.begin(), dopa2.end());
    print(dopa2);

    // Q3. 거꾸로 된 문자열 끝에 문자열 추가
    dopa2 += "testString";
    print(dopa2);

    return 0;
}

/*
abc
cba
cbatestString
*/