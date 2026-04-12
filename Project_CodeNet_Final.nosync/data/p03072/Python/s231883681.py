n = int(input());hl = [int(n) for n in input().split()][:n];print(sum([1 for ln in[len([n for n in hl[:i] if n>hl[i]]) for i in range(n)] if ln == 0]))
