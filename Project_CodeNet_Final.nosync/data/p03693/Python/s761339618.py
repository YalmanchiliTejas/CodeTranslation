a, b, c = [int (i) for i in raw_input ().split ()]
print ["NO", "YES"][(100 * a + 10 * b + c) % 4 == 0]
