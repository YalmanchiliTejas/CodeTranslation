import fileinput


def algorithm(input_lines):
    c = input_lines[0]
    return "vowel" if c in "aiueo" else "consonant"


def run():
    out = algorithm([l.strip() for l in fileinput.input()])
    print(out)


run()
