#!/usr/bin/env python3

import re
print("Yes") if len(re.findall(r"AC", input())) > 0 else print("No")
