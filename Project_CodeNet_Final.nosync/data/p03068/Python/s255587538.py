n = int(input())
s = input()
k = int(input())
target = s[k-1]
for i, obj in enumerate(s):
    if obj is not target:
        s = s.replace(obj, "*")
print(s)