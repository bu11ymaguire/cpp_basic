#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> hello(N+1,0);
    for(int i = 1; i <= N; i++)
    {
        cin >> hello[i];
    }

    vector<vector<bool>> bellin(N+1,vector<bool>(N+1,false));

    for(int L = 1; L <= N; L++)
    {
        for(int s = 1; s <= N - L +1; s++)
        {
            int e = s + L -1;
            if(hello[s]==hello[e])
            {
                if(s+1 <= e - 1)
                {
                    bellin[s][e] = bellin[s+1][e-1];
                }
                else{
                    bellin[s][e] = true;
                }
            }
        }
    }

    

    /*

    for(int i =1; i <N-1;i++) //길이가 3인 경우
    {
        if(hello[i]==hello[i+2]){
            bellin[i][i+2] = true;
        }
    }
    우선 S번째 숫자랑 E번째 숫자가 같은 지 확인.
    그리고 나서 S번째랑 E번째가 같으면 S-1번째와 E-1번째를 확인.
    bellin[S][E] = bellin[S+1][E-1] && (number[S]==number[E])
    */
    int m; cin >> m;
    while(m--)
    {
        int from, to; cin >> from >> to;
        cout << (int)bellin[from][to] << '\n';
    }

    return 0;
}