def read_line(*types): return [f(a) for a, f in zip(input().split(), types)]

a, b, c, x, y = read_line(int, int, int, int, int)

if a + b < 2 * c:
    print(x * a + y * b)
else:
    z = min(x, y)
    count = z * (c * 2)
    if x == z:
        count += (y - z) * min(b, c * 2)
    else:
        count += (x - z) * min(a, c * 2)
    print(count)
            
        

