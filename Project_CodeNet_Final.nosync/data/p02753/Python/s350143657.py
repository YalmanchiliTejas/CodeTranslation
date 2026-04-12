import sys
input = sys.stdin.readline

s = input()
s_unique = ''.join(set(s))

# print(len(s_unique))

if len(s_unique) == 2:
    print("No")
else:
    print("Yes")