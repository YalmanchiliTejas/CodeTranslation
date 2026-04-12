import sys

stacks = []

no_stacks = int(input())
for _ in range(no_stacks):
    stacks.append([])

for operation in sys.stdin:
    operation = operation.strip()

    if operation.startswith('quit'):
        break

    elif operation.startswith('push'):
        _, index, block = operation.split()
        stacks[int(index)-1].append(block)

    elif operation.startswith('pop'):
        _, index = operation.split()
        print(stacks[int(index)-1].pop())

    elif operation.startswith('move'):
        _, src_index, dst_index = operation.split()
        stacks[int(dst_index)-1].append(stacks[int(src_index)-1].pop())