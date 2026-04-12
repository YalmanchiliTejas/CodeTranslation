#coding:utf-8

if __name__ == "__main__":
    N = int(input())
    tmp = input().split()
    Hs = []
    for t in tmp:
        Hs.append(int(t))
    total = 0

    for n in range(N):
        n_count = 0
        for i in range(0, n):
            if Hs[i] > Hs[n]:
                break
            n_count += 1
        if n_count == n:
            total += 1
        
    print(total)