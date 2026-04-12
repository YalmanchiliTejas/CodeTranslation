_, string, pos = [raw_input() for i in range(3)]
char = string[int(pos) - 1]
out = ""
for i in string:
    out += (i if i == char else "*")
print(out)