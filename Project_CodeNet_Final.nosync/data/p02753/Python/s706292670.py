if __name__ == '__main__':
    bus = [a.strip() for a in input()]
    if bus == ['B','B','B'] or bus == ['A','A','A']:
        print('No')
    else:
        print('Yes')