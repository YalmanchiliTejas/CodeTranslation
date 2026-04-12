N = int(input())
H = list(map(int,input().split()))
L = [H[0]]
for i in range(N-1):
  if max(H[:i+1]) <= H[i+1]:
    L.append(H[i+1])
print(len(L))