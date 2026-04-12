import sys
input = sys.stdin.readline

N= int(input().rstrip('\n'))
As = [int(x) for x in input().rstrip('\n').split()]
s = sum(As)**2
b = sum(x**2 for x in As)
print(((s-b)//2)%1000000007)