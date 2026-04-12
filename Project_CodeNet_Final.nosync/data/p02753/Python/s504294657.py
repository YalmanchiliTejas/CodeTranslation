s = input()
list_s = list(s)

print("No") if s[0] == s[1] and s[1] == s[2] and s[2] == s[0] else print("Yes")