def main():
    N,X,M = map(int,input().split())
    dict = {key:0 for key in range(M)}
    #print(dict)
    if N==1:
        return X
    dict[X] += 1
    cnt = 1
    A = [0]*(M+1)
    A[1] = X
    ans = X
    tmp = X
    for i in range(1,N,1):
        tmp = (tmp**2)%M
        if dict[tmp] != 0:
            break
        ans += tmp
        A[i+1] = A[i]+tmp
        cnt += 1
        dict[tmp] += cnt

    num = N - cnt#残り足す回数
    roop_num = cnt - dict[tmp] + 1
    syo = num//roop_num
    amari = num%roop_num
    ans += syo*(A[cnt]-A[dict[tmp]-1])
    ans += (A[dict[tmp]+amari-1]-A[dict[tmp]-1])
    return ans

print(main())
