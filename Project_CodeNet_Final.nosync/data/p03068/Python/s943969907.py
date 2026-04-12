n = int(input())
s = input()
k = int(input())

key = s[k-1]
new_s = ''
for st in s:
    if st != key:
        new_s = new_s + '*'
    else:
        new_s = new_s + key

print(new_s)