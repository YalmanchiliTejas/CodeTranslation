import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def list_duplicate(l, m):
    if len(l) <= len(m):
        l1 = l
        l2 = m
    else:
        l1 = m
        l2 = l
    ret = []
    for v in l1:
        if v in l2:
            ret.append(v)
            l2.remove(v)
    return ret

n = int(readline())
l = list(readline().decode().rstrip())
for _ in range(n - 1):
    m = list(readline().decode().rstrip())
    l = list_duplicate(l, m)
l.sort()

print("".join(l))