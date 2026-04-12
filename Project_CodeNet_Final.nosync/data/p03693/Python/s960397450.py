N = list(map(int, input().split()))
x = sum([N[i]*(10**(2-i)) for i in range(3)])
print("YES") if x % 4 == 0 else print("NO")