N, M = map(int, input().split())
links = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
paths = 0

def search(cur, last):
    global paths
    if len(last) == 0:
        paths += 1
        return
    
    for i in list(last):
        if sorted([cur, i]) in links:
            pass_last = last.copy()
            pass_last.remove(i)
            search(i, pass_last)
    
search(0, set(range(1, N)))
print(paths)
            