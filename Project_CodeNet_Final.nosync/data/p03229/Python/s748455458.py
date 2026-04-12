N=int(input())
A=sorted(int(input()) for _ in [0]*N)

if N%2:
    a = A[:N//2]
    b = A[N//2+1:][::-1]
    m = A[N//2]
    if abs(m-a[-1])>abs(m-b[-1]):
        a,b = b,a
    B = [m]*N
    for i in range(N//2):
        B[2*i+1] = b[i]
        B[2*i+2] = a[i]
else:
    a = A[:N//2][::-1]
    b = A[N//2:][::-1]
    B = [0]*N
    for i in range(N//2):
        B[i*2] = a[i]
        B[i*2+1] = b[i]
ans = sum(abs(B[i]-B[i+1]) for i in range(N-1))
print(ans)