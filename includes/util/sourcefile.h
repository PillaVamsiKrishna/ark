#ifndef __SOURCE_FILE_H
#define __SOURCE_FILE_H

#include <stdlib.h>

#include "vector.h"
#include "util.h"
#include "parser.h"

#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Transforms/Scalar.h>

/**
 * Source file properties
 */
typedef struct {
	sds fileName;            // file name for the source file
	char *name;              // file name for the source file, raw
	char *fileContents;      // the contents of the file
    LLVMModuleRef module;
	Vector *tokens;          // the token stream for the source file
	Vector *ast;             // the output AST tree
} SourceFile;

/**
 * Create a source file with the given file
 * @param fileName the file name
 */
SourceFile *createSourceFile(sds fileName);

/**
 * Destroy the source file
 * @param sourceFile the sourceFile to destroy
 */
void destroySourceFile(SourceFile *sourceFile);

#endif // __SOURCE_FILE_H
