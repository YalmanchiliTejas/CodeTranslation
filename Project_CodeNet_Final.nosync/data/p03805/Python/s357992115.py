import copy


class Line:
    def __init__(self, a, b):
        self.a = a
        self.b = b


def generate_patterns(remains, current_pattern, patterns):
    if len(remains) == 0:
        patterns.append(current_pattern)
        return
    for remain in remains:
        _current_pattern = copy.copy(current_pattern)
        _current_pattern.append(remain)
        _remains = copy.copy(remains)
        _remains.remove(remain)
        generate_patterns(_remains, _current_pattern, patterns)
    return patterns


N, M = map(int, input().split())
lines = []
for _ in range(M):
    a, b = map(int, input().split())
    lines.append(Line(a, b))

m = {}
for i in range(1, N+1):
    m[i] = {}
    for j in range(1, N+1):
        m[i][j] = False

for line in lines:
    m[line.a][line.b] = True
    m[line.b][line.a] = True

remains = []
for i in range(2, N+1):
    remains.append(i)
patterns = generate_patterns(remains, [1], [])

cnt = 0
for pattern in patterns:
    countable = True
    for i in range(len(pattern)-1):
        current = pattern[i]
        next = pattern[i+1]
        if not(m[current][next]):
            countable = False
            break
    if countable:
        cnt += 1

print(cnt)
