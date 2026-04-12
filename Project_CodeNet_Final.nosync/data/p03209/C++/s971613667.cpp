#import<iostream>

main(){
    int_fast64_t N, X, P, r(0);
    std::cin >> N >> X;
    P = 1LL << N;
    while(X){
        if(!N){
            ++r;
            break;
        }
        if(X < 2 * P - 1)
            --X;
        else{
            r += P;
            X += 1 - P * 2;
        }
        --N;
        P >>= 1;
    }
    std::cout << r;
    puts("");
}