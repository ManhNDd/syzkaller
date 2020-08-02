// Copyright 2017 syzkaller project authors. All rights reserved.
// Use of this source code is governed by Apache 2 LICENSE that can be found in the LICENSE file.

package sys

import (
	// Import all targets, so that users only need to import sys.
	_ "github.com/ManhNDd/syzkaller/sys/akaros/gen"
	_ "github.com/ManhNDd/syzkaller/sys/freebsd/gen"
	_ "github.com/ManhNDd/syzkaller/sys/fuchsia/gen"
	_ "github.com/ManhNDd/syzkaller/sys/linux/gen"
	_ "github.com/ManhNDd/syzkaller/sys/netbsd/gen"
	_ "github.com/ManhNDd/syzkaller/sys/openbsd/gen"
	_ "github.com/ManhNDd/syzkaller/sys/test/gen"
	_ "github.com/ManhNDd/syzkaller/sys/windows/gen"
)
