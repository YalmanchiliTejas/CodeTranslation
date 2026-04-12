INF = 999999999999999999L
EPS = 1e-12

def read():
    return raw_input().strip()

def read_ints():
    return map(int,read().split())

s = read()
if "AC" in s:
    print "Yes"
else:
    print "No"