n = int(input())
h = list(map(int,input().split()))
print(sum([max(h[0:i+1])==h[i] for i in range(n) ]))