from sys import stdin, stdout  
  
n = stdin.readline()
arr = [int(x) for x in stdin.readline().split()] 

summation = 0
for x in arr: summation += x
sqsum = 0
for x in arr: sqsum += (x*x)

ans = (summation*summation - sqsum) // 2
ans = (ans % 1000000007)

stdout.write(str(ans)) 

