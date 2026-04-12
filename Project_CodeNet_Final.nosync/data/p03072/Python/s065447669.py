N = int(input())
H = list(map(int, input().split()))
print (sum([1 for i in range(1,N) if max(H[:i]) <= H[i]]) + 1)