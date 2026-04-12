_, e, f = [input() for _ in range(3)]

print("".join([char if char == e[int(f)-1] else "*" for char in e]))