N = int(input())
A = []
for i in range(N):
    a = int(input())
    A.append(a)
B = [A[0]]
for i in range(1, N):

    if A[i] > B[-1]:#2分探索でどこかに入れる
        sm = -1
        la = len(B)-1
        
        while sm+1<la:
            mi = (sm+la)//2
            if B[mi]<A[i]:
                la=mi
            else:
                sm=mi
        B[la]=A[i]
        
    else:#Bに追加
        B.append(A[i])

print(len(B))