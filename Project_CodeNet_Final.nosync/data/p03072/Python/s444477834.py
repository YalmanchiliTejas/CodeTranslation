N = int(input())
H = list(map(int,input().split()))
L = [H[0]]
count = 1
for i in range(1,len(H)):
  L.append(H[i])
  if max(L) == L[-1]:
    count += 1
    
print(count)