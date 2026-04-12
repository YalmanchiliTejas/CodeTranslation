memo1 = {}
def cho(n):
    if n==0:
        return 1
    if n in memo1:
        return memo1[n]
    memo1[n] = 2*cho(n-1)+3
    return memo1[n]
memo2 = {}
def pat(n):
    if n==0:
        return 1
    if n in memo2:
        return memo2[n]
    memo2[n] = 2*pat(n-1)+1
    return memo2[n]
N,X = map(int,input().split())
cnt = 0
k = N
while X>0:
    if X==1:
        if k==0:
            cnt += 1
        break
    elif X<=cho(k)//2:
        k -= 1
        X -= 1
    elif X==cho(k)//2+1:
        cnt += 1+pat(k-1)
        break
    elif X==cho(k):
        cnt += pat(k)
        break
    else:
        cnt += pat(k-1)+1
        X -= cho(k-1)+2
        k -= 1
print(cnt)