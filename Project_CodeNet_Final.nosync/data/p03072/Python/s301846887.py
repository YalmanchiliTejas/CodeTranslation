N=int(input())
H=list(map(int, input().split()))
count = 1
for i in range(1,N):
  n = len([1 for x in H[0:i] if x>H[i]])
  if n==0:
    count = count + 1
print(count)