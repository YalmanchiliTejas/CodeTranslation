#!/usr/bin/env python3

def main():
    N = input()
    l = len(N)
    K = int(input())

    ans = 0
    # 最上位K桁が0の場合
    # l-K_C_K * 9^K
    if K == 1:
        ans += (l-1) * 9
    elif K == 2:
        ans += (l-1) * (l-2) * 81 // 2
    else:
        ans += (l-1) * (l-2) * (l-3) * 729 // 6

    if K == 1:
        # 最上位の数以外0
        ans += int(N[0])
    elif K == 2:
        # 最上位1桁が0ではなく,残りl-1桁中1桁だけ0以外（Nより大きくならないように注意）
        if l >= 2:
            # ans += int(N[0]) * (l-1) * 9 - (9 - int(N[1]))
            for a in range(1,int(N[0])+1):
                for b in range(l-1):
                    for p in range(1,10):
                        tmp = a * 10**(l-1) + p * 10**b
                        if tmp <= int(N):
                            ans += 1
    else:
        # 最上位1桁が0ではなく,残りl-1桁中2桁だけ0以外（Nより大きくならないように注意）
        if l >= 3:
            NN = int(N)
            N0 = int(N[0])
            L = 10**(l-1)

            ans += (N0-1) * (l-1) * (l-2) * 81 // 2

            for p in range(1,10):
                for q in range(1,10):
                    for b in range(l-1):
                        for c in range(b+1,l-1):
                            tmp = N0 * L + p * 10**b + q * 10**c
                            if tmp <= NN:
                                ans += 1
                            else:
                                break
    print(ans)

if __name__ == "__main__":
    main()
