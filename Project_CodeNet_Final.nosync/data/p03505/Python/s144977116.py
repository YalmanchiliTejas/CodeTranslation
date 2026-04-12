K,A,B = map(int,input().split())
if A >= K:
    print(1)
elif A > B:
    #n = math.ceil((K-A) / (A-B))
    n = (K-A-1) // (A-B) + 1
    print(2*n + 1)
else:
    print(-1)
