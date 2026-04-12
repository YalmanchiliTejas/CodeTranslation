def feasible():
    n, m = map(int, raw_input().split())
    g = [ raw_input().strip() for r in range(n) ]
    start = 0
    for row in g:
        in_row = False
        found_row = False
        for c, ch in enumerate(row):
            if ch == '.':
                in_row = False
                continue
            if c < start:
                return False
            if not in_row and found_row:
                return False
            in_row = True
            found_row = True
            start = c
    return True
                
print('Possible' if feasible() else 'Impossible')
