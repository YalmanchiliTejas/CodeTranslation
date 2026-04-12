a, b = map(int, raw_input().split())
s = 'a == b'
if a < b:
    s = 'a < b'
elif a > b:
    s = 'a > b'
print s