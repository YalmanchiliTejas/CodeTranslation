def f(M,N):
    if M==N:
        return 'Yes'
    else:
        return "No"
N,M=map(int,input().split())
print(f(M,N))