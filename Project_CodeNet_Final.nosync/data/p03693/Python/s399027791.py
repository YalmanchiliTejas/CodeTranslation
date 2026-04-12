a = list(input().split())
n = int("".join(map(str, a)))
print("YES" if n % 4 == 0 else "NO")