from sys import stdin
a, b, c, x, y = [int(x) for x in stdin.readline().rstrip().split()]
print(min([i*2*c+max(0, x-i)*a+max(0, y-i)*b for i in range(10**5+1)]))