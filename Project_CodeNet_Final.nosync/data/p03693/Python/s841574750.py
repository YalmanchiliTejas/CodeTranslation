color = list(map(str, input().split()))
print("YES" if int("".join(color)) % 4 == 0 else "NO")
