a, b = map(int, raw_input().split(' '))
print [x for x in ["a < b", "a == b", "a > b"] if eval(x)][0]