N = int(input())
H = list(map(int, input().split()))
H2 = [H[i] for i in range(N) if H[i] >= max(H[:i+1])] 
print(len(H2))
