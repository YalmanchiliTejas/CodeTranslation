s = input()
print("No" if all(map(lambda c: c == s[0], s)) else "Yes")
