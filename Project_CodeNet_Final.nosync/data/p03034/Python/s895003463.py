N = int(input())
s = list(map(int,input().split()))

ans = 0
for c in range(1,N-1):
    ltor = [0]
    for p in s[::c]:
        ltor.append(ltor[-1] + p)
    rtol = [0]
    for p in s[N-1::-c]:
        rtol.append(rtol[-1] + p)
    A = N-1-c
    while c < A:
        if A % c == 0 and A + c * (A//c-1) < N-1:
            break
        ind = (N-1-A)//c+1
        temp = ltor[ind] + rtol[ind]
        ans = max(temp,ans)
        A -= c

print(ans)

