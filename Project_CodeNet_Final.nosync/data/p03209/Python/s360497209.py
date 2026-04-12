
def count(N):
    pn = 2**(N+1)-1 #パテ
    bn = 2**(N+1)-2 #バン
    rn = pn + bn    #バーガー枚数(右端)
    return pn, bn, rn
    
if __name__ == "__main__":
    N, X = map(int, input().split())
    pn,bn,rn = count(N)
    mid = (1+rn)//2
    cnt = 0
    # Xの位置関係で場合分け
    while N > 0:
        # print(X,"l m r",1,mid,rn)
        # print("cnt",N,cnt)
        pn_prev, bn_prev, rn_prev = count(N-1)

        if X == 1:
            break
        elif X == mid:
            cnt +=  pn_prev + 1
            break
        elif rn == X:
            cnt += 2*pn_prev + 1
            break
        elif 1 < X < mid:
            X -= 1
        elif mid < X < rn:
            cnt += pn_prev + 1
            X -= mid

        pn, bn, rn = pn_prev,bn_prev,rn_prev
        mid = (1+rn)//2
        N -= 1
        if N == 0:
            cnt += 1
    print(cnt) #0段目のパテ