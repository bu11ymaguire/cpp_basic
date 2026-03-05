#include<bits/stdc++.h>
using namespace std;

/*
맨 처음에는 NC3개의 삼각형의 개수들을 다 합쳐서 구하는 것인줄 알았다.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double sum = 0;
    int N; cin >> N;
    vector<pair<double,double>> code(N);

    for(int i = 0; i < N ; i++)
    {
        cin >> code[i].first >> code[i].second;
    }

    double x = code[0].first;
    double y = code[0].second;

    for(int i = 0; i < N - 2; i++)
    {
        double x1 = code[i+1].first - x;
        double y1 = code[i+1].second - y;

        double x2 = code[i+2].first - x;
        double y2 = code[i+2].second - y;

        sum+= (x1 * y2) - (x2 * y1);
    }

    sum *= 0.5;
    cout << fixed << setprecision(1) << abs(sum);

    return 0;
}