from sys import stdin
 
N = int(input())
H = [int(x) for x in stdin.readline().rstrip().split()]
 
c = 1
for i in reversed(range(1,N)):
  if H[i] - H[i-1] >= 0 and H[i] == max(H[:i+1]):
    c += 1
 
print(c)