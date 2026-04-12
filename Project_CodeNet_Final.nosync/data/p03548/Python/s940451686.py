X, Y, Z = map(int, input().split())

def is_ok(key):
    if key * Y + (key + 1) * Z <= X:
        return True
    else:
        return False

def binary_search():
    ok = 0
    ng = 3000001
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if is_ok(mid):
            ok = mid
        else:
            ng = mid
    return ok

print(binary_search())