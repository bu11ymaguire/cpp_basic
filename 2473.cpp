#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> hello(N);

    for(int i = 0; i < N; i++)
    {
        cin >> hello[i];
    }

    sort(hello.begin(),hello.end());

    /*
    long long sum = LONG_LONG_MAX;
    int L =0; int R = N-1;
    int one,two,three;

    while(L<=R)
    {
        long long sam = hello[L] + hello[R];
        if(abs(sam+hello[L+1])<=abs(sam+hello[R-1]))
        {
            if(abs(sam+hello[L+1])<sum)
            {
                sum = abs(sam+hello[L+1]);
                one = L;
                two = L + 1;
                three = R;
                R--;
            }
        }
        else
        {
            if(abs(sam+hello[R-1])<sum)
            {
                sum = abs(sam+hello[R-1]);
                one = L;
                two = R-1;
                three = R;
                L++;
            }
        }
    }
    cout << one <<' '<< two <<' '<< three;
    */
   long long sum = LONG_LONG_MAX;
   vector<int> arr(3);

   for(int i = 0; i < N-2; i++)
   {
    int L = i + 1;
    int R = N - 1;

    while(L<R)
    {
        long long now = (long long)hello[i] + hello[L] + hello[R];

        if(abs(now)<sum)
        {
            arr[0] = hello[i];
            arr[1] = hello[L];
            arr[2] = hello[R];
            sum = abs(now);
        }

        if(now<0){
            L++;
        }else if(now >0){
            R--;
        }else{ //0이면 그 즉시 종료.
        for(const auto& hi : arr){
        cout << hi <<' ';} 
        return 0;
        }
    }
   }
   for(const auto& hi : arr)
   {
    cout << hi <<' ';
   } 
    return 0;
}