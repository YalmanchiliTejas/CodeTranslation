def solve(s):
    return "Yes" if len(set(s)) > 1 else "No"

s = input()
print(solve(s))
