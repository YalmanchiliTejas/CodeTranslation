a, b = map(int, raw_input().split(' '))

if a > b:
    op = ">"
elif a < b:
    op = "<"
else:
    op = "=="

print("a " + op + " b")