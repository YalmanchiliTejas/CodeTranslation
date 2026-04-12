from sys import stdin
x,y,z = [int(_) for _ in stdin.readline().rstrip().split()]
print(int((x-z)/(y+z)))