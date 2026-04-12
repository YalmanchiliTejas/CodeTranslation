N=int(input())
A=[int(input()) for _ in range(N)]


#新しい値が最小なら追加，そうでなければそれを超えない最大の値を書き換え
#降順
b=[]
b.append(A[0])


def bi_s(n):
    if b[-1]>=n:
        return -1
    if n>b[0]:
        return 0
    
    ceil=0
    floor=len(b)-1
    med=1#len(b)==2のとき
    while abs(floor-ceil)>1:
        med=(ceil+floor)//2
        if n>b[med]:
            floor=med
        else:
            ceil=med
    return floor

for i in range(1,N):
    index=bi_s(A[i])
    if index==-1:
        b.append(A[i])
    else:
        b[index]=A[i]
print(len(b))